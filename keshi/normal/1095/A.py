n=int(input())
a=input()
b=''
f=1
s=0
while n:
    b+=a[s]
    s+=f
    n-=f
    f+=1
print(b)