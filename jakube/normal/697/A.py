t, s, x = map(int, input().split())

if x < t+s:
    if x == t:
        print("YES")
    else:
        print("NO")
else:
    x -= t + s
    if (x % s) < 2:
        print("YES")
    else:
        print("NO")