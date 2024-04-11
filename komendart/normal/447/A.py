def main():
    p, n = [int(i) for i in input().split()]
    
    d = [0 for i in range(p)]
    
    for i in range(n):
        x = int(input()) % p
        if d[x]:
            print(i + 1)
            return
        d[x] = 1
    
    print(-1)


main()