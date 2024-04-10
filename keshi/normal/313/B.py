s=input()
a=len(s)*[0]
for i in range(1,len(a)):
    a[i]=a[i-1]
    if s[i]==s[i-1]:
        a[i]+=1
m=int(input())
s=''
for i in range(m):
    l,r=map(int,input().split())
    s+=str(a[r-1]-a[l-1])+'\n'
print(s)