n=int(input())
a=[0]*1000
for i in range(n):
    s=input()
    t1=s[0]+s[1]
    t2=s[3]+s[4]
    a[i]=60*int(t1)+int(t2)
for i in range(n):
    for j0 in range(i,n-1):
        j=n+i-2-j0
        if (a[j]>a[j+1]):
            q=a[j+1]
            a[j+1]=a[j]
            a[j]=q
a[n]=24*60+a[0]
mx=a[0]
for i in range(n):
    mx=max(mx,a[i+1]-a[i]-1)
q1=(mx//60)
q2=(mx%60)
if q1==0:
    s1="00"
elif q1<10:
    s1="0"+str(q1)
else:
    s1=str(q1)

if q2==0:
    s2="00"
elif q2<10:
    s2="0"+str(q2)
else:
    s2=str(q2)
print(s1+":"+s2)