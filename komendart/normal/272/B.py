def main():
    from collections import defaultdict
    
    def f(x):
        if x < L:
            return prec[x]
        return f(x // 2) + x % 2
    
    n = int(input())
    
    a = [int(i) for i in input().split()]
    
    L = 10**5
    prec = [0]
    for i in range(1, L):
        if i % 2 == 1:
            prec.append(prec[i - 1] + 1)
        else:
            prec.append(prec[i // 2])
    
    d = defaultdict(int)
    
    for i in a:
        d[f(i)] += 1
    
    result = 0
    for i in d.values():
        result += i * (i - 1) // 2
    
    print(result)

main()