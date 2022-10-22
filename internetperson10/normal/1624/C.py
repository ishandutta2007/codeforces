t = int(input())
for _ in range(t):
    n = int(input())
    l = [int(x) for x in input().split()]
    s = set()
    ok = True
    for x in l:
        while x > 0:
            if x <= n and x not in s:
                s.add(x)
                break
            else:
                x //= 2
        if x == 0: # nothing worked
            ok = False
    print("YES" if ok else "NO")
    s.clear()