def isup(s):
    for i in s:
        if i>"Z":
            return 0
    return 1
a=input()
if isup(a[1:]):
    b=""
    for i in a:
        if i>"Z":
            b+=chr(ord(i)-32)
        else:
            b+=chr(ord(i)+32)
    a=b
print(a)