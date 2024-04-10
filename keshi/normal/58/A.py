a=input()
b=list("hello")
for i in a:
    if i==b[0]:
        b.pop(0)
        if not b:
            break
if b:
    print("NO")
else:
    print("YES")