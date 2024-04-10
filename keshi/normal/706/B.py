n=int(input())
a=list(map(int,input().split()))
dp=100001*[0]
for i in a:
    dp[i]+=1
for i in range(1,len(dp)):
    dp[i]+=dp[i-1]
d=int(input())
for i in range(d):
    print(dp[min(100000,int(input()))])