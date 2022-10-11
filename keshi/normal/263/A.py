x,y=0,0
for i in range(5):
    a=list(map(int,input().split()))
    if 1 in a:
        y=i
        x=a.index(1)
print(abs(x-2)+abs(y-2))