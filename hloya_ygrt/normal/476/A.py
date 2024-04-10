inp = input().split()
n = int(inp[0])
m = int(inp[1])

i = int(0)
ans = int(2000000000)
while i <= n:
	y = n - (2 * i)
	if y < 0:
	   i = i + 1
	   continue
	if ( (i + y) % m == 0):
		ans = min(ans,i + y)
   #print(i,ans)
	i = i + 1 

if (ans == 2000000000):
	print(-1)
else:
	print(ans)