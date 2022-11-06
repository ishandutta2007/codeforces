import bisect
n,m=[int(i) for i in input().split()]
t=[int(i) for i in input().split()]
s=[t[0]]
ans='0'
k=t[0]
for i in t[1:]:
    k+=i
    if(k<=m):
        ans=ans+' '+'0'
    else:
        j=1
        h=0
        while(h<(k-m)):
            h+=s[-j]
            j+=1
        ans=ans+' '+str(j-1)
    bisect.insort(s,i)
print(ans)