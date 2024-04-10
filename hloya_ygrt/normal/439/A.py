inp = input().split()
n =   int(inp[0])
d =   int(inp[1])
sum = 0
inp =  input().split()
for i in range(n):
	sum = sum + int(inp[i])
ans = 0
ost = 0
#print(sum)
if sum+(n-1)*10 > d:
   print(-1)
   exit()

ans = (n-1)*2
#print(ans)
ost = int(d - (ans*int(5)) - sum)

#print(ost)
ans += ost // 5

print(ans)