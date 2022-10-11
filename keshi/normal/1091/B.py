n=int(input())
x,y=0,0
for i in range(n*2):
    a,b=map(int,input().split())
    x+=a
    y+=b
print(x//n,y//n)