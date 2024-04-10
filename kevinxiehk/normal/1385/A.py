t=int(input())
for _ in range(t):
    x,y,z=list(map(int, input().split(' ')))
    if x!=y and y!=z and x!=z:
        print("NO")
    elif (x==y and y<z)or(x==z and y>z)or(y==z and x>y):
        print("NO")
    else:
        print("YES")
        if x==y:
            print(str(x)+" "+str(z)+" 1")
        elif x==z:
            print(str(y)+" "+str(x)+" 1")
        elif y==z:
            print("1 "+str(x)+" "+str(z))