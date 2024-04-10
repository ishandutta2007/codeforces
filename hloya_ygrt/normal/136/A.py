a = []
b = []
n = input()
a = input().split()
x = int(1)
n = int(n)
for j in range(101):
    b.append(1)

out = ""
x = int(1)
i = int(0)
while x <= n:
    b[int(a[i])] = x
    x = x + 1
    i = i + 1

x = int(1)
while (x <= n):
    out = out + str(b[x]) + " "
    x = x + 1
print(out)