def main():
    n, m = [int(i) for i in input().split()]
    
    k = n // m
    n1 = (k + 1) * m - n
    
    minimal = n1 * k * (k - 1) // 2 + (m - n1) * (k + 1) * k // 2
    
    maximal = (n - m + 1) * (n - m) // 2
    
    print(minimal, maximal)


main()