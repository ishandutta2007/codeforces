n = input()
s = input()

any_in = lambda p, s: any(x in s for x in p.split())

if any_in("CC YY MM", s):
    print("No")
elif any_in("?? C?C M?M Y?Y", "?"+s+"?"):
    print("Yes")
else:
    print("No")