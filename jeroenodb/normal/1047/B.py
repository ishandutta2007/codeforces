n = int(input())
ans = 0
for i in range(n):
    x,y = map(int,input().split())
    ans = max(x+y,ans)
print(ans)