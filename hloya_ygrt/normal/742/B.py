n, q = map(int,input().split())
a = list(map(int, input().split()))

ans = 0
f = {}
for i in a:
        y = i ^ q
        z = f.get(y)
        if z != None:
                ans += z
        if f.get(i) != None:
                f[i] += 1
        else:
                f[i] = 1
print(ans)