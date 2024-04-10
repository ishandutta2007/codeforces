MAX=10**5+1
n=int(input())
a=list(map(int,input().split()))
b=MAX*[0]
for i in a:
    b[i]+=1
dp=MAX*[0]
dp[1]=b[1]
for i in range(1,MAX):
    dp[i]=max(dp[i-1],dp[i-2]+i*b[i])
print(dp[-1])