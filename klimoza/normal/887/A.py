s = input()
c = 0
bl = False
for i in s:
    if bl and i == "0":
        c+=1
    elif not bl and i == "1":
        bl = True
if c>=6:
    print("yes")
else:
    print("no")