#Bartek Kostka
#  You are not prepared!

s = input()
s = "1*" + s + "*1"

IL = []

for i in range(len(s)):
    if s[i] == "*":
        IL.append(i)

maks = 0
for i in range(len(IL)):
    for j in range(i+1,len(IL)):
        a = eval(s[:IL[i]+1]+"("+s[(IL[i]+1):IL[j]]+")"+s[IL[j]:])
        maks = max(maks, a)
print(maks)