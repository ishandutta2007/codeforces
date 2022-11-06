def lowbit(x):
    i = 0
    while x & 1 == 0:
        x >>= 1
        i += 1
    return 1 << i

def main():
    Sum, limit = [int(i) for i in input().split()]
    
    d = {}
    for i in range(1, limit + 1):
        tmp = lowbit(i)
        if tmp not in d:
            d[tmp] = []
        d[tmp].append(i)
    
    result = []
    i = Sum
    while i > 0 and Sum:
        if i in d and d[i]:
            result.append(d[i].pop())
            Sum -= i
            i = min(Sum, i)
        else:
            i -= 1
    
    if Sum:
        print("-1")
    else:
        print(len(result))
        for i in result:
            print(i, end=' ')
    

main()