a = input()
b = input()
c = input()
d = input()

s = list(a + b[1] + b[0])
t = list(c + d[1] + d[0])
s.remove('X')
t.remove('X')

for i in range(5):
    t = t[1:] + [t[0]]
    if s == t:
        print("YES")
        break
else:
    print("NO")