def main():
    n, t = [int(i) for i in input().split()]
    if n == 1 and t == 10:
        print(-1)
    else:
        x = t
        while len(str(x)) < n:
            x *= t
        print(x)
    
main()