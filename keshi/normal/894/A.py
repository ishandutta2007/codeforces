a=0
d=0
ans=0
for i in input():
    if i=="Q":
        ans+=d
        a+=1
    elif i=="A":
        d+=a
print(ans)