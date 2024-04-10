inp = input().split()
n = int(inp[0])
m = int(inp[1])
inp = input().split()
a = []
for i in range(m):
    a.append(int(inp[i]))
a.sort()
ans = int(1001)
i = n-1
while i < m:
    ans = min(ans,a[i] - a[i-n+1])
    i = i + 1
print(ans)