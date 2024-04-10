s=input()
if s[0]>"Z":
    print(chr(ord(s[0])-32),end='')
else:
    print(s[0],end='')
print(s[1:])