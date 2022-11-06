def main():
    n = int(input())
    a = [int(i) for i in input().split()]
    
    mi = min(a)
    d = 0
    p = n + a.index(mi)
    for i in range(n - 1, -1, -1):
        if a[i] == mi:
            p = i
        d = max(d, p - i)
    print(mi * n + d)
    
    
    
main()