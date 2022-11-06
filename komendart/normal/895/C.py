from collections import defaultdict
def getmask(x):
    ans = 0
    for i in range(2, x + 1):
        while x % i == 0:
            x //= i
            ans ^= 1 << i
    return ans

def main():
    maxn = 71
    n = int(input())
    a = [int(i) for i in input().split()]
    cnt = [0] * maxn
    for i in a:
        cnt[i] += 1
    masks = defaultdict(int)
    for i in range(1, maxn):
        masks[getmask(i)] += cnt[i]
    while masks[0] != sum(masks.values()):
        fixed = max(i for i in masks if masks[i])
        masks[0] -= 1
        for i in list(masks.keys()):
            if i ^ fixed < i:
                masks[i ^ fixed] += masks[i]
                masks[i] = 0
    print(pow(2, masks[0], 10**9+7) - 1)
    
    
    
main()