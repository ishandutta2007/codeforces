n, x = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
j = 0
t = 0
for i in range(x):
    if j >= len(a):
        break
    elif i == a[j]:
        j += 1
    elif i < a[j]:
        t += 1
if j >= len(a):
    t = x - j
elif a[j] == x:
    t+=1
print(t)