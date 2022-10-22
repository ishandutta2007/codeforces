n = int(input())
node = [[] for i in range(n)]
for i in range(1,n):
    a,b = map(int,input().split())
    node[a-1].append(b-1)
    node[b-1].append(a-1)

dp = [[] for i in range(n)]
def combine(a, b):
    c = [0]*(len(a)+len(b)-1)
    for i,va in enumerate(a):
        for j,vb in enumerate(b):
            c[i+j] = max(c[i+j],va*vb)
    return c

def dfs(p,par=-1):
    dp[p] = [0,1]
    for i in node[p]:
        if i == par: continue
        dfs(i,p)
        dp[p] = combine(dp[i],dp[p])
    ma = 0
    for i,v in enumerate(dp[p]):
        ma = max(ma, i*v)
    dp[p][0] = ma
dfs(0)
print(dp[0][0])