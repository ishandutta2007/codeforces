n = input()
a = [int(x) for x in input().split()]
f = lambda x: all(abs(a-b) < 2 for a,b in zip(a, a[1:]))
while a:
    if not f(a):
        print("NO")
        exit(0)
    m = max(a)
    a = [x for x in a if x != m]
print("YES")