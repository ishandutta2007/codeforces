def foo ():
    global a, n
    n = int(raw_input())
    a = [int(i) for i in raw_input().split()]
    a.append(a[0])
    bestv = 10000
    for i in range(n):
        if abs(a[i] - a[i + 1]) < bestv:
            bestv = abs(a[i] - a[i + 1])
            bestnum = i
    print (bestnum) % n + 1, (bestnum + 1) % n + 1
foo()