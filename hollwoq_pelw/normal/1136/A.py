n = int(input())
l = []
for i in range(n):
    s, t = input().split()
    l.append((int(s), int(t)))
d = int(input())
#print(*l)
for (a, b) in l:
    if d > b:
        n-=1
print(n)