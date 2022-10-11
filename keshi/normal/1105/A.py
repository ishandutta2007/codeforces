def get():
    return list(map(int,input().split()))
def check(a,x):
    f=0
    for i in a:
        if i>x:
            f+=i-x-1
        elif i<x:
            f+=x-i-1
    return f
n=int(input())
a=get()
f=min(a)
b=[]
for i in range(min(a),max(a)+1):
    b+=[check(a,i)]
g=b.index(min(b))
print(g+f,b[g])