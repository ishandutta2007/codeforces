a=input()
if a=="{}":
    print(0)
else:
    print(len(set(a[1:-1].split(", "))))