a=list(input())
b=''
if len(a)%2:
    while a:
        b+=a.pop(len(a)//2)
else:
    while a:
        b+=a.pop((len(a)+1)//2-1)         
print(b)