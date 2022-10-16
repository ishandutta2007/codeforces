x = input()
ans = x.count("Danil");
ans += x.count("Olya");
ans += x.count("Slava");
ans += x.count("Nikita");
ans += x.count("Ann");
if ans == 1:
	print("YES")
else:
	print("NO")