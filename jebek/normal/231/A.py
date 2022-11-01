n=input()
ans=0
for i in range(n):
    if sum(map(int,raw_input().split()))>1:
        ans+=1
print ans