n = int(input())
a = [input() for _ in range(n)]
a.sort(key=len)

if all(x in y for x, y in zip(a, a[1:])):
    print("YES")
    for s in a:
        print(s)
else:
    print("NO")