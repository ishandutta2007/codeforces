n=input()
ans=0
sum=0
for i in range(n):
    sum-=eval(raw_input().replace(' ','-'))
    ans=max(ans,sum)
print ans