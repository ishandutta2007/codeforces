n=int(input())
ma=0
mb=0
s=''
for i in range(n):
    a=input().split()
    a[1]=int(a[1])
    a[2]=int(a[2])
    if a[2]<a[1]:
        a[1],a[2]=a[2],a[1]
    if a[0]=='+':
        ma=max(ma,a[1])
        mb=max(mb,a[2])
    else:
        if a[1]>=ma and a[2]>=mb:
            s+="YES\n"
        else:
            s+="NO\n"
print(s)