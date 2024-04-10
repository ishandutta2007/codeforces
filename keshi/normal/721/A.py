n=int(input())
s=input()+"W"
a=[]
f=-1
if s[0]=="B":
    f=0
for i in range(1,n+1):
    if s[i]=="W" and f!=-1:
        a+=[i-f]
        f=-1
    elif f==-1 and s[i]=="B":
        f=i
print(len(a))
print(*a)