w,h=map(int,input().split())
a,b=map(int,input().split())
c,d=map(int,input().split())
while h:
    w+=h
    if h==b:
        w=max(0,w-a)
    elif h==d:
        w=max(0,w-c)
    h-=1
print(w)