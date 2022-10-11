n=int(input())
s=0
l=''
for i in range(n):
    a=input()
    if a!=l:
        s+=1
    l=a
print(s)