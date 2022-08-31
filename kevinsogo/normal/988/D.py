def pows2(n):
    p2 = 1
    while p2 <= n:
        yield p2
        p2 <<= 1

def maxseq(l, d):
    prev = -float('inf')
    best = []
    curr = []
    for v in l:
        if v - prev != d: curr = []
        curr.append(v)
        prev = v
        if len(best) < len(curr):
            best = curr
    return best

n = int(input())
x = sorted(map(int, input().split()))
ans = []
for p2 in pows2(max(x) - min(x) + 1):
    y = {}
    for v in x:
        vs = v % p2
        if vs not in y or len(y[vs]) >= 3 or v - y[vs][-1] != p2: y[vs] = []
        y[vs].append(v)
        ans = max(ans, y[vs], key=len)

print(len(ans))
print(*ans)