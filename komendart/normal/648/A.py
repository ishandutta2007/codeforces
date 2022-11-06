def main():
    n, m = [int(i) for i in input().split()]
    d = [list(input()) for i in range(n)]
    
    a = [0] * m
    for i in range(m):
        for j in range(n):
            if d[j][i] == '*':
                a[i] += 1
    
    x = y = 0
    for i in range(1, m):
        if a[i] > a[i - 1]: x = max(x, a[i] - a[i - 1])
        else: y = max(y, a[i - 1] - a[i])
    
    print(x, y)
    
    
main()