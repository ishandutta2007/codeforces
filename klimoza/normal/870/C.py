q = int(input())
for i in range(q):
    n = int(input())
    if n%2 == 0:
        if n % 4 == 0:
            print(n//4)
        elif n == 2:
            print(-1)
        else:
            print(1 + ((n-6)//4))
    else:
        if n < 9:
            print(-1)
        else:
            t = n - 9
            if t % 4 == 0:
                print(1 + (t//4))
            elif t == 2:
                print(-1)
            else:
                print(2 + ((t - 6)//4))