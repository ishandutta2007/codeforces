n=int(input())
f=0
for i in range(n):
    a,b=map(int,input().split())
    if b>a:
        f-=1
    if a>b:
        f+=1
if f>0:
    print("Mishka")
elif f<0:
    print("Chris")
else:
    print("Friendship is magic!^^")