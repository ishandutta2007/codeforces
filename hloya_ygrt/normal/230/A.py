inp = input().split()
s = int(inp[0])
n = int(inp[1])

a = []

for i in range(n):
	inp = input().split()
	b = []
	b.append(int(inp[0]))
	b.append(int(inp[1]))
	a.append(b)
a.sort()
ans = 1
for i in range(n):
   #print(a[i][0])
   if (a[i][0] >= s):
	    ans = 0
	    break
   #s -= a[i][0]
   s += a[i][1]

if ans:
	print("YES")
else:
	print("NO")