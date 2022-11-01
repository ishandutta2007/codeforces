def can(a,j):
    for i in a:
        if (i == j):
            return True
    return False
need = int(input())
inp = input().split()
n = int(inp[0])
a = []
b = []
for i in range(n+1):
    if (i!=0):
      a.append(int(inp[i]))
inp = input().split()
m = int(inp[0])
for i in range(m+1):
    if (i!=0):
      b.append(int(inp[i]))
now = 1
while now <= need:
    if (can(a,now)):
        now = now + 1
        continue
    if (can(b,now)):
        now = now + 1
        continue
    break
if now == need + 1:
    print("I become the guy.")
else:
    print("Oh, my keyboard!")