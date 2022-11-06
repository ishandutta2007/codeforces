def main():
    n, m, k = [int(i) for i in input().split()]
    
    if k > n + m - 2:
        print(-1)
        return
    
    if k > n - 1:
        result1 = m // (k + 2 - n)
    else:
        result1 = n // (k + 1) * m
    
    if k > m - 1:
        result2 = n // (k + 2 - m)
    else:
        result2 = m // (k + 1) * n
    
    print(max(result1, result2))

main()