n=input()
ans=0
for i in range(n):
    if raw_input()[1]=='+' :
        ans+=1
    else:
        ans-=1
print ans