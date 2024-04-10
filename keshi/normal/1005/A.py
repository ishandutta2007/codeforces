input()
a=list(map(int,input().split()))+[1]
s=[]
f=0
a.remove(1)
while 1 in a:
    s+=[a.index(1)-f+1]
    f=a.index(1)
    a.remove(1)
print(len(s))
print(*s)