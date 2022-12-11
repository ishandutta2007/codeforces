n = int(input())

if (n == 2):
    print(-1)
else:
    lst = [2]
    while (len(lst) < n):
        d = lst[len(lst) - 1]
        d += 1
        while True:
            ok = True
            x = 2
            while (x * x <= d):
                if (d % x == 0):
                    ok = False
                    break
                x += 1
            if (ok):
                lst.append(d)
                break
            else:
                d += 1
        
    prod = 1 
    for x in lst:
        prod *= x 
    for x in lst:
        print(prod // x)