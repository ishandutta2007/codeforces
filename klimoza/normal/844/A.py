s = input()
n = int(input())
a = []
t = 0
for i in s:
    if i not in a:
        a.append(i)
    else:
        t += 1
siz = len(a)
if siz >= n:
    print(0)
elif n - siz <= t:
    print(n - siz)
else:
    print("impossible")