def get():
    return list(map(int,input().split()))
a,b,c=get()
x,y,z=get()
if x<a:
    print("NO")
else:
    x-=a
    if x+y<b:
        print("NO")
    elif x+y+z-b<c:
        print("NO")
    else:
        print("YES")