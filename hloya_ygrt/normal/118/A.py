def sogl(s):
    return not(s=="a" or s == "o" or s == "y" or s == "e" or s == "u" or s == "i")
s = input()
t = ""
n = int(len(s))
for i in range(n):
    if s[i].isupper():
        x = ord(s[i])
        x = x - ord("A")
        x = x + ord("a")
        t = t + chr(x)
    else:
        t = t + s[i]
#print(t)
s = ""

for i in range(n):
    if sogl(t[i]):
        s = s + '.' + t[i]

print(s)